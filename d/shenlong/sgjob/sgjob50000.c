//Cracked by Kafei
// /d/shenlong/sgjob/sgjob50000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "̫��ʮ����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "����Ƭ",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "ʯ��",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             50,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "��ϼ����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             200,
                "pot_bonus":             50,
                "score":                 2
        ]),

        ([      "sgjob":          "�ȷ�ͼ��",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "������",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "��ʬ��",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "��",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "���ĵ�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "�ɺ�ҩ",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             5,
                "score":                 1
        ]),

        ([      "sgjob":          "����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":            120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "����ɢ",
                "sgjob_type":           "Ѱ",
                "exp_bonus":            100,
                "pot_bonus":             30,
                "score":                 1
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),
        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}

