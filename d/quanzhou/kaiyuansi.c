// Room: /d/quanzhou/kaiyuansi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��Ԫ��");
	set("long", @LONG
����һ����ģ����ǧ���ɲ����������������𣬴�ͩ��ӳ��
���Ŵ�������δ����ǰ��ԶԶ�ɼ�����ʯ����ն��𣬴�����ǧ¥��
��֮�ϡ�����������������꣬ȫ��ռ���Ӵ��Ǹ������ķ�̽���
֮һ��������������棬������ʯ���ˣ���ֲ��ͩ�����ſ�����������
���ﲻ��������͡�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"westroad2",
		"north" : __DIR__"tianwangdian",
	]));
	set("objects", ([
		"/d/wudang/npc/guest" : 2,
	]));
	set("coor/x", 1830);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
