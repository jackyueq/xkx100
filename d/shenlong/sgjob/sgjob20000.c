//Cracked by Kafei
// /d/shenlong/sgjob/sgjob20000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "���¾�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             10,
                "pot_bonus":             3,
                "score":                 1
        ]),

        ([      "sgjob":          "�����޶�����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "���������ᾭ",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             40,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "������",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "��ɽ����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "��ʫѡ��",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "���ҵ�����ƪ",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             250,
                "pot_bonus":             60,
                "score":                 2
        ]),

        ([      "sgjob":          "����Ӣ����",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 1
        ]),

        ([      "sgjob":          "������",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "������",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "�����������Ͼ�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "�����������¾�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "����������Ͼ�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "����������¾�",
                "sgjob_type":           "Ѱ",
                "exp_bonus":             30,
                "pot_bonus":             8,
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

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
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


