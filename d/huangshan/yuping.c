// Room: /d/huangshan/yuping.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
��Ⱥ�ߴ�Ľ�������Ϊ���������壬�����ֳ�����¥���ڴ˿��Ծ�
������������������ɫ�������춼����ɽ��ֱ��ɽ�ţ�������ֱ������
������ǡ�ơ�ͻأ����񷡱��ʢ��ܽ�ء�������ش������������ģ���
��ɽ�澰��ɣ����ĺ�����������ɽ�ӣ������桱�������ֲ���ֳ�
����ɽ��ʤ������
LONG
	);
	set("exits", ([ 
		"north"     : __DIR__"lianhua",
		"southeast" : __DIR__"yingke",
		"southwest" : __DIR__"lianrui",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
