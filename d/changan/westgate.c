// /d/changan/westgate.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "������");
        set  ("long",  @LONG
������ǳ�������----�����š�����Ϊ�೯�Ŷ�����Ȼ��ͬ���죬
��ǽ��ʯ�ҡ�Ŵ�׺������ɣ��������������������ű��ֱͨ���ݣ���
���ٱ��������š�
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            "west"  :  __DIR__"road7",
            "east"  :  __DIR__"westroad1",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
	set("coor/x", -5070);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

