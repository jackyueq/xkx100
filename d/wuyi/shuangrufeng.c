// Room: /d/wuyi/shuangrufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "˫���");
	set("long", @LONG
˫����������ٷ塢���ӷ壬Ϊ������߷塣ԶԶ��ȥ������ͦ��
���������޲����˾�̾�ͳ����컯�칤֮���ӡ���������ұ��ϣ���һ
�Ҷ���������ʮ�ˣ��ഫΪ������������ڣ�����СѨ�ڻ�������й�
���˵����ɡ�������ͽС��⹫������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest"  : __DIR__"path9",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4960);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

