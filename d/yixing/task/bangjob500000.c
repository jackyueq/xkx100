//Cracked by Kafei
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "���ݳǼ���",
                "type"  :  "ɱ",
                "bonus" :  100,
                "score" :  40,
        ]),

        ([      "name"  :  "��һ��",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "�ض�",
                "type"  :  "ɱ",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/forest/npc/peng-lianhu",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  60,
                "score" :  15,
        ]),

        ([      "name"  :  "������",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  50,
                "score" :  12,
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
