// Room: /binghuo/lingshetop.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���������ߵ�ɽ���������︩����ݰ�����ߵ���Ƕ��տ����
���У�һ������������̧ͷԶ��������ν�̲���������һɫ�ˣ�
�����Ľ�󿪡����ߵ�����ƫƧ������Ҳ������ʲô��ֻ����������
ʱ�������ӿ������⣬ֻ�в����ĺ����Х�ˡ�
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"      : __DIR__"lingsheroom",
		"southdown"  : __DIR__"lingsheroad3",
		"eastdown"   : __DIR__"lingsheroad4",
	]));
	setup();
	replace_program(ROOM);
}

