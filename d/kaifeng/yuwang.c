// /kaifeng/yuwang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨������Сɽ��֮�ϣ�����羰�������������ţ��Թ�������
�������δ��Ǹߵ�ʤ�ء��ഫ����ʱ�ڣ�����ä����ʦ�����ڴ˴����
�֣���������̨����
LONG);
	set("objects", ([
		__DIR__"npc/woman" : 1,
	]));
	set("exits", ([
		"west"   : __DIR__"shulin",
		"eastup" : __DIR__"yuwangmiao",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
