//Cracked by Kafei
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/foshan/npc/baoshu",
                "area"  :  "������",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  70,
                "score" :  30,
        ]),

        ([      "name"  :  "�ձ�����",
                "file"  :  "/d/quanzhou/npc/langren",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  7,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/hangzhou/npc/yang",
                "area"  :  "ţ�Ҵ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "��Х��",
                "file"  :  "/d/hangzhou/npc/guo",
                "area"  :  "ţ�Ҵ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "����",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "�ܵ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "ָ��",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
