// Room: /d/suzhou/dongting.c
// Last Modified by winder on Mar. 8 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ŷ�������֪���д����˵����ڡ����а���һ��ɼľԲ��
�ͼ������ӣ�������һ�׾��µ����˴�����ǽ�Ϲ���һ�����ã�������
�ͻ���ɽ������֪�����ֱʡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"yamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", 845);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

