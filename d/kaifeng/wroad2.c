// /kaifeng/wroad2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ������������˳�������
�̷���ߺ�ȣ�������С�����ּۻ��������ޱȡ������������ۣ�����
�����ϵ���¥��
LONG);
	set("objects", ([
		__DIR__"npc/qigai" : 1,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"west"   : __DIR__"yanqing",
		"eastup" : __DIR__"jiaolou1",
		"north"  : __DIR__"wroad3",
		"south"  : __DIR__"wroad1",
	]));

	setup();
	replace_program(ROOM);
}
