// Room: /d/yueyang/shijie7.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
���������������ʯ�ף��±߾��Ƕ�ͥ������ͷ��ʯ������������
�����࣬������ʪ������մȾ��Ũ�ص�����ζ��ʯ��������һЩ��ؤ��
�����������Ȼ����룬�������֡���ʱҲ��һЩ���Ű�����ȴ�¹�����
���ˣ���æ�ڱǶ�����
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south"    : __DIR__"dianjiangtai",
		"eastup"   : __DIR__"ximen",
		"westdown" : __DIR__"matou1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 3,
	]));
	set("coor/x", -1440);
	set("coor/y", -2270);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
