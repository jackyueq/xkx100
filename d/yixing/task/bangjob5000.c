//Cracked by Kafei
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�ػ�",
                "file"  :  "/d/quanzhou/npc/huihui",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  4,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "area"  :  "�����庣��",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  3,
        ]),

        ([      "name"  :  "��ɳ������",
                "file"  :  "/d/hangzhou/npc/hsbz",
                "area"  :  "����������",
                "type"  :  "ɱ",
                "bonus" :  18,
                "score" :  5,
        ]),

        ([      "name"  :  "��ӥ����",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "area"  :  "�����庣����",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  5,
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


