inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ��
��������������߷ɳ۶���������һ·��������·���������������
�����֡�
LONG );
	set("exits", ([
		"east"      : __DIR__"road4",
		"northwest" : __DIR__"road6",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 0);
	set("coor/y", 3200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

