// yuhuayuan2.c ����԰

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����ǻ����ͻ�������԰. ƽ�������ʱ���������, �͹�������
һ���ͻ�Ʒ��. ����, �����ƽ��̫��, ������������. ����Ĺ�Ů��
����������, ��ͨ������. �����Ĺ�, ��Ŀ�����ƽ�����, ����ϸ�ֱ�, 
��ȻƷĿ��ȫ, ������õ�, �������붼�������, ���ﶼ����. ��
������Щ�ʼ���ʵ��϶���.
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"  : __DIR__"yihexuan",
		"north" : __DIR__"qinandian",
		"south" : __DIR__"yuhuayuan",
                "west"  : __DIR__"majuan",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
		__DIR__"obj/tuofengbai" : 1,
		__DIR__"obj/longzao" : 1,
		__DIR__"obj/zheyinhou" : 1,
	]) );
	set("coor/x", -200);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}