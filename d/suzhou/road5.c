// Room: /d/suzhou/road5.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ϴ��");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ���������������ݳ��ˡ����ϱ߰��ߣ������������׷���׺������
����������̫���ˡ������̲���Ư��һҶҶ��С��, һ�����ö���С
�������ź��ϵ���粻ʱƮ����Ķ��С�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"road6",
		"southwest" : "/d/yanziwu/hupan",
	]));
	set("coor/x", 850);
	set("coor/y", -1130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
