// Room: /d/wuxi/taibomiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "̩����");
	set("long", @LONG
����Զ��ʱ�ڣ�̩�����⣬�����ﴫ�ڵ�����ʶ�֡���֯����չ��
��ҵ��ұͭҵ���͵춨�˽����Ļ��Ļ�����̩��Ҳ����ܵ��˵�������
�ľ��غͰ������������˴�������������������������һ�Խ����ͷ��
��������Ƿ�չ�ˣ����˷������̩������֮���⣬���������Ҳ����
���ˡ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"road9",
		"west" : "/d/guiyun/road1",
	]));
	set("coor/x", 340);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
