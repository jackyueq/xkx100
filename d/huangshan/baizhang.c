// Room: /d/huangshan/baizhang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
��ɽ��������֮һ�������ֱ�¶������ɹ���ͤԶ����Ϊ׳�ۣ���
�˽��ۣ��������齦��ˮ��������һ������֮���������������һ��
���ķ��顣����ľ����ٸ��Ǿ��ѡ�
LONG
	);
	set("exits", ([ 
		"west"   : __DIR__"qingluan",
		"eastup" : __DIR__"jiulong",
	]));
	set("resources/water",1);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
