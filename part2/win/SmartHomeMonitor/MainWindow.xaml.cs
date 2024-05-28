using MahApps.Metro.Controls;
using System;
using System.Windows;
using System.Diagnostics;
using SmartHomeMonitoringApp.Views;
using System.ComponentModel;

namespace SmartHomeMonitoringApp
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void MetroWindow_Loaded(object sender, RoutedEventArgs e)
        {
        }

        // 끝내기 버튼 클릭이벤트 핸들러
        private void MnuExitProgram_Click(object sender, RoutedEventArgs e)
        {
            Process.GetCurrentProcess().Kill();  // 작업관리자에서 프로세스 종료!
            Environment.Exit(0); // 둘중하나만 쓰면 됨
        }

        // MQTT 시작메뉴 클릭이벤트 핸들러
        private void MnuStartSubscribe_Click(object sender, RoutedEventArgs e)
        {
        }

        private async void MetroWindow_Closing(object sender, CancelEventArgs e)
        {
        }

        private void BtnExitProgram_Click(object sender, RoutedEventArgs e)
        {
        }

        private void MnuDataBaseMon_Click(object sender, RoutedEventArgs e)
        {
            ActiveItem.Content = new DataBaseControl();
            StsSelScreen.Content = "데이터베이스 모니터링";
        }

        private void MnuRealTimeMon_Click(object sender, RoutedEventArgs e)
        {
            ActiveItem.Content = new RealTimeControl();
            StsSelScreen.Content = "실시간 모니터링";
        }

        private void MnuVisualizationMon_Click(object sender, RoutedEventArgs e)
        {
        }

        private void MnuAbout_Click(object sender, RoutedEventArgs e)
        {
        }

        private void MnuVisialization_Click(object sender, RoutedEventArgs e)
        {
            ActiveItem.Content = new VisualizationControl();
            StsSelScreen.Content = "시각화 모니터링";
        }
    }
}
