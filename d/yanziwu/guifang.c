//ROOM: /d/yanziwu/guifang.c

inherit ROOM;

void create()
{
	set("short", "���뷿");
	set("long",@LONG
������ǰ��������ı�����Ů���������Ĺ뷿�ˡ���С����Ȼ�귽
�׳ݣ����ǰ�Ū�����Ǹ��ڽ�����˭Ҳ���µĵ���ȴ�Ǿ����������
�š�һ�ｵһ�����������Ҳͬʱ����֤������һ������������
���ж���ĥ����
LONG );
	set("exits", ([
		"east": __DIR__"jinfeng",
	]));
	set("objects", ([
		__DIR__"npc/bao": 1,
	]));
	set("coor/x", 740);
	set("coor/y", -1550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}