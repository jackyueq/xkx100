// Room: /heizhao/pubu.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
��첽�߽��ٲ���ֻ������������ͷ�����ң��������£�����
һ��ʯ�ϣ����Դ��������ٲ�ˮ���ļ��쳣��һк��ע��ˮ������
���㣿��Ȼ���㣬��������Ͼ�̶���������ʱ������˫Ŀһ������
������ˮ�С�
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("resource/water", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/yu" : 1,
	]));
	set("exits", ([
		"southup" : __DIR__"shanlu9",
		"enter"   : __DIR__"xiaowu",
	]));
	set("coor/x", -5020);
	set("coor/y", -1280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}