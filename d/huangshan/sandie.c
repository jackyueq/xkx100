// Room: /d/huangshan/sandie.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
��ͷ���������������ǻ�ɽ����Ȫ�е�һ������Ϊ��ɽ��й��Ȫˮ
�������������γ����۶���������Զ�۽�����������Χ���ĵ�ɽ�֣���
�������ױȵ�ʤ��������Ȫ��Զ������Ȫ��
LONG
	);
	set("exits", ([ 
		"southup" : __DIR__"zuishi",
		"north"	  : __DIR__"mingxuan",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
