//      caoyuan.c ��ԭ

inherit ROOM;

void create()
{
        set("short","��ԭ");
        set("long",@LONG
������ѩɽ���µ�һƬ��ԭ�������������Ⱥɽ��ɽ���ϻ�������
������ѩ��������һ����·��
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "west"      : __DIR__"tulu1",
                "northeast" : "/d/xingxiu/silk5" ,
        ]));
        set("objects",([
                __DIR__"npc/yetu" : 4 ,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -25000);
	set("coor/y", -5000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
