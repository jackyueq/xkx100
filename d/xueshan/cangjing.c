//      cangjingge.c �ؾ���

inherit ROOM;

void create()
{
        set("short","�ؾ���");
        set("long",@LONG
������ѩɽ�µĲؾ�֮����������������ܶ������ĵ伮����һ��
��Ҳ��������
LONG );
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));

        set("coor/x", -69990);
	set("coor/y", -19900);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

