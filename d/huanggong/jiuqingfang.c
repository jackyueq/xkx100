// jiuqing.c

inherit ROOM;

void create()
{
	set("short", "���䷿");
	set("long", @LONG
��������������Ͷ���Ժ��ʷ���������䡢ͨ��ʹ˾ͨ��ʹ�Ⱦ���
��Ա�Լ����������մ󳼵Ⱥ�����ټ��ĳ���, �������ɹ�����ֵ��, 
����Ҳ��"��©��".
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"qianqingmen",
	]));
	set("coor/x", -190);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}