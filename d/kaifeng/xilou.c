// /kaifeng/xilou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "Ϸ¥");
	set("long", @LONG
һ��ľͷ�ִִ���ĸ�̨��̨�ĺ���ô���������������Ǻ�ͷ��
��Ϸ��װ����̨�ĵط��������ǹص����Ե�ʣ��ݵ��޷�����԰�����塢
������ǧ�����ն���۵ȹ��¡�
LONG);
	set("objects", ([
		__DIR__"npc/qingyi" : 1,
		__DIR__"npc/xiaosheng" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"paifang",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
