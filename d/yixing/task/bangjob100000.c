//Cracked by Kafei
// /d/huanghe/bangjob/bangjob100000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�����",
                "file"  :  "/d/forest/npc/banhe",
                "area"  :  "���ݽ���",
                "type"  :  "ɱ",
                "bonus" :  50,
                "score" :  15,
        ]),

        ([      "name"  :  "��ͨ��",
                "file"  :  "/d/huanghe/npc/hou-tonghai",
                "area"  :  "�ƺӰ���",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "�ݳ���",
                "file"  :  "/d/foshan/npc/changfa",
                "area"  :  "����",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "���ӹ�",
                "file"  :  "/d/jiaxing/npc/huang",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ",
                "bonus" :  75,
                "score" :  25,
        ]),

        ([      "name"  :  "�ڰ���",
                "file"  :  "/d/jiaxing/npc/heibai",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "ͺ����",
                "file"  :  "/d/jiaxing/npc/tubiweng",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ",
                "bonus" :  65,
                "score" :  20,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/jiaxing/npc/danqing",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ", 
                "bonus" :  60,
                "score" :  17,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/jiaxing/npc/dingjian",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ",
                "bonus" :  45,
                "score" :  10,
        ]),

        ([      "name"  :  "ʩ����",
                "file"  :  "/d/jiaxing/npc/shilingwei",
                "area"  :  "����÷ׯ",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "½��Ӣ",
                "file"  :  "/d/taihu/npc/guanying",
                "area"  :  "����ׯ",
                "type"  :  "ɱ",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
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

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}

