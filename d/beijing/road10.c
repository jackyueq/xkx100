inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ��
��������������߷ɳ۶���������һ·��������·���������������
�����֡����߾��Ǵ�֮���ˡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"haigang",
		"north" : __DIR__"road9",
		"south" : "/d/nanyang/ruzhou",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 10);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

