// shijianyan.c �Խ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�Խ���");
        set("long", @LONG
ʯ��������һ�����ʯ������߲߰����ľ��ǿ��ˡ�������
ʯ����ȫ��̵��Խ��ң����µ�Ӣ��������������ȱ�������ʱ
����ʯ�ϵĿ��ۣ��޲���Ȼ�𾴡�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 110);
	set("coor/z", 160);
	setup();
        replace_program(ROOM);
}