//Cracked by Kafei
// /d/huanghe/bangjob/bangjob20000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/guidao",
                "area"  :  "��������¥",
                "type"  :  "ɱ",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "�տն�",
                "file"  :  "/d/city/npc/qigai.c",
                "area"  :  "���ݳ�",
                "type"  :  "ɱ",
                "bonus" :  50,
                "score" :  20,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/forest/npc/chang",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "����Ӱ",
                "file"  :  "/d/forest/npc/hua",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "��ң��",
                "file"  :  "/d/forest/npc/xiaoyaozi",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/dao-ke",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/jian-ke",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "����ͷ",
                "file"  :  "/d/wudang/npc/tufeitou",
                "area"  :  "�䵱ɽ",
                "type"  :  "ɱ",
                "bonus" :  50,
                "score" :  17,
        ]),

        ([      "name"  :  "����ɢ",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "������",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "����ͼ",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  10,
                "score" :  3,
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
