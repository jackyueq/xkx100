// /kaifeng/wroad3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ������������˳�������
�̷���ߺ�ȣ�������С�����ּۻ��ۣ������ޱȡ��ϱ߲�Զ��������ۡ�
��������ͤ԰��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"tingyuan",
		"south" : __DIR__"wroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
