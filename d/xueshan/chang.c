// chang.c ���䳡

inherit ROOM;

void create()
{
        set("short","���䳡");
        set("long",@LONG
������ѩɽ�����䳡�����źö�ľ׮��ɳ����ɮ�����ճ����ڴ�ϰ
�䡣�����ǹ㳡�������и�С�ⷿ���ϱ�һ��Ƭ�����أ�����ѩɽ����
���ڵļ�̳�ˡ�
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
                "south" : __DIR__"jitan",
        ]));
        set("objects", ([
//                CLASS_D("xueshan")+"/gelunbu" :1,
		__DIR__"npc/x_lama" : 1 ,
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -70050);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}

