//Cracked by Kafei
// /d/huanghe/changle/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�����",
                "file"  :  "/d/emei/npc/xiang-ke",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  8,
                "score" :  2,
        ]),

        ([      "name"  :  "Ƥ����",
                "file"  :  "/d/changbai/npc/phshang",
                "area"  :  "����ɽ����",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/foshan/npc/pang",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  5,
                "score" :  1,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/foshan/npc/shou",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  5,
                "score" :  1,
        ]),

        ([      "name"  :  "С��",
                "file"  :  "/d/quanzhou/npc/mao-fan",
                "area"  :  "Ȫ�����Ĺ㳡",
                "type"  :  "ɱ",
                "bonus" :  6,
                "score" :  2,
        ]),

        ([      "name"  :  "Ұ�ջ�",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "Ѱ",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "name"  :  "��Ƥ",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "Ѱ",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
        ]),

        ([      "type"  :  "̯��",
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

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
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



