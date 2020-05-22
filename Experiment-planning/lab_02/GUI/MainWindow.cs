using System;
using System.Collections.Generic;
using System.Text;
using Gtk;
//using SMOElementsLibrary;
using ExperimentsLibrary;
using TimeElementsLibrary;

public partial class MainWindow : Gtk.Window
{
    public MainWindow() : base(Gtk.WindowType.Toplevel)
    {
        Build();
    }

    protected void OnDeleteEvent(object sender, DeleteEventArgs a)
    {
        Application.Quit();
        a.RetVal = true;
    }

    protected void OnStartModellingBtnClicked(object sender, EventArgs e)
    {
        //bool ifGenIntense = GenIntenseRBtn.Active;
        //double genIntense = GenIntenseSBtn.Value;
        //double genSigma = GenSigmaSBtn.Value;

        //bool ifProcIntense = false;
        //double procM = ProcMSBtn.Value;
        //double procSigma = ProcDSBtn.Value;
        //double procIntense = 0;

        //double modellingTime = ModellingTimeSBtn.Value;

        //ModellingController controller = new ModellingController(ifGenIntense, genSigma, genIntense,
        //    ifProcIntense, procM, procSigma, procIntense, modellingTime);
        //Report report = controller.StartModelling();

        //StringBuilder stringBuilder = new StringBuilder();
        //stringBuilder.Append(report.ToString());

        //stringBuilder.Append(PlotGenerator.GetAvgTime(genIntense, procM, procSigma));

        //ResTextView.Buffer.Clear();
        //ResTextView.Buffer.Text = stringBuilder.ToString();
    }

    protected void OnStartExperimentClicked(object sender, EventArgs e)
    {
        StringBuilder builder = new StringBuilder();

        double minGenIntense = MinGenIntense.Value; double maxGenIntense = MaxGenIntense.Value;
        double minProcIntense = MinProcIntense.Value; double maxProcIntense = MaxProcIntense.Value;

        double genIntense = GenIntense.Value;
        double procIntense = ProcIntense.Value;

        FIntenseExperiment experiment =
            new FIntenseExperiment(minGenIntense, maxGenIntense, minProcIntense, maxProcIntense, genIntense, procIntense);

        experiment.GetModellingResults();

        //for (int i = 0; i < 4; i++)
        //{
        //    builder.Append($"{experiment.ExperimentResults[i]:F2}\n");
        //}

        builder.Append("\n");

        double[] coeffs = experiment.GetCoeffs();

        //for (int i = 0; i < coeffs.Length; i++)
        //{
        //    builder.Append($"{coeffs[i]:F2}\n");
        //}

        experiment.GetExperimentParams();

        double exp = PlotGenerator.IntenseExperiment(genIntense, procIntense);
        double linExp = experiment.LinExperiment();
        double nonLinExp = experiment.NonLinExperiment();

        double[] loads = new double[4];
        loads[0] = minGenIntense / minProcIntense;
        loads[1] = minGenIntense / maxProcIntense;
        loads[2] = maxGenIntense / minProcIntense;
        loads[3] = maxGenIntense / maxProcIntense;

        Array.Sort(loads);
        builder.Append($"Загрузка системы лежит в интервале [{loads[0]:F2}, {loads[3]:F2}]\n\n");

        builder.Append($"Коэффициенты линейного плана:\n");
        for (int i = 0; i < 3; i++)
        {
            builder.Append($"b{i} = {coeffs[i]:F2}\n");
        }

        builder.Append("\n\n");
        builder.Append($"Коэффициенты частично нелинейного плана:\n");
        for (int i = 0; i < 3; i++)
        {
            builder.Append($"b{i} = {coeffs[i]:F2}\n");
        }
        builder.Append($"b12 = {coeffs[3]:F2}\n");


        builder.Append("\n\n");
        builder.Append($"Среднее время ожидания заявки в очереди {exp:F4}\n");
        builder.Append($"Результат линейного плана {linExp:F4}\n");
        builder.Append($"Результаты частично нелинейного плана {nonLinExp:F4}\n");

        double linDelta = Math.Abs(exp - linExp) / exp * 100;
        double nonLinDelta = Math.Abs(exp - nonLinExp) / exp * 100;

        builder.Append("\n\n");
        builder.Append($"Отклонение линейного плана = {linDelta:F2}%\n");
        builder.Append($"Отклонение частично нелинейного плана = {nonLinDelta:F2}%\n");

        ResTextView.Buffer.Clear();
        ResTextView.Buffer.Text = builder.ToString();
    }
}
