// shandong2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
ɽ�����ѩ��£�ɼ���ѩ�ѣ�����ʱ������ɨ����ѩ����ǰ�����
��������ԼԼ��һ��ɽ����
LONG );
        set("exits",([
                "enter" : __DIR__"shandong3",
                "west"  : __DIR__"sroad9",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/baoxiang" :1,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -109900);
	set("coor/y", -55000);
	set("coor/z", 300);
	setup();
        replace_program(ROOM);
}