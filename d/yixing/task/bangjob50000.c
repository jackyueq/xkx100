//Cracked by Kafei
// /d/huanghe/changle/bangjob50000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "������",
                "file"  :  "/d/xingxiu/npc/hasake",
                "area"  :  "��ɽ����",
                "type"  :  "ɱ",
                "bonus" :  15,
                "score" :  4,
        ]), 

        ([      "name"  :  "Ԭ����",
                "file"  :  "/d/forest/npc/guannan",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]), 

        ([      "name"  :  "������",
                "file"  :  "/d/forest/npc/lin",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "�η���",
                "file"  :  "/d/forest/npc/ren",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "��ǧ��",
                "file"  :  "/d/huanghe/npc/qiu",
                "area"  :  "�ƺӰ���",
                "type"  :  "ɱ",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "���л�",
                "file"  :  "/d/forest/npc/zhonghui",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/jiaxing/npc/xiang",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "name"  :  "���˴�",
                "file"  :  "/d/quanzhou/npc/jiarenda",
                "area"  :  "Ȫ��ɽ·",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
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
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}

