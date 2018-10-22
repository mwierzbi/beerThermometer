<template>
    <div>
        <GChart
                :settings="{ packages: ['gauge'] }"
                type="Gauge"
                :data="chartData"
                :options="chartOptions"
        />
    </div>
</template>

<script>
    import { GChart } from 'vue-google-charts'
    export default {
        name: "Gauge",
        components: {
            GChart
        },
        props: ['value'],
        data() {
            return {
                chartOptions: {
                    width: '100%', height: '100%',
                    redFrom: 90, redTo: 100,
                    yellowFrom:75, yellowTo: 90,
                    minorTicks: 5
                }
            };
        },
        computed: {
            chartData: function() {
              return [
                  ['Label', 'Value'],
                  ['temp (°C)', this.value],
              ]
            }
        }
    }
</script>

