//      guangchang.c �㳡

inherit ROOM;

void create()
{
        set("short","�㳡");
        set("long",@LONG
������ѩɽ���ڵĹ㳡���㳡ʯ���̾ͣ�����������ƽ������ʵ��
�㳡�ı��������ɽ������ѩɽ�´������ǿ����䳡��������ɽ�š�
������һЩ�ֳ�ɮ����ɮ����Ѳ�ߡ�
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 4 ,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}
