import argparse
from src.algs.sorting import MergeSort
from src.algs.sorting import SelectionSort


def run(args):
    sr = SelectionSort(args.lista)
    sr.sort()
    mr = MergeSort(args.lista)
    mr.sort()
    print('Array ordinato: {}'.format(sr.ar))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-l',
        '--lista',
        nargs='+',
        help='Lista degli elementi da ordinare. Passarli nel formato x1 x2 ... xn',
        default=[5, 3, 1, 2])
    args = parser.parse_args()
    args.lista = [int(val) for val in args.lista]
    run(args)
