// /guanwai/muqiao.c

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ�����ʧ�޵���ľ�ţ��ɼ��������������ɡ�����ĺ�ˮ��
�Խ�ɼ�������ﱾ�Ǻ�ͼ�����ǵĻ��Ǻӣ����ѷ��������ˡ��Ӱ���
�����û����ѳɵĳ�ǽ���ܶദ����̮�����ɴ��򱱾��Ǻ�ͼ�������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"nancheng",
		"south" : __DIR__"road8",
	]));
	set("objects", ([
		__DIR__"npc/yuzhenzi" : 1,
	]));
	set("outdoors", "guanwai");
	set("coor/x", 6040);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}