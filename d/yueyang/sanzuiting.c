// Room: /d/yueyang/sanzuiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ��λ������¥���࣬Ϊ��¥��֮ͤһ���ķ��θ����ɣ�����
���ܣ�Ъɽ�������ߺ���������ׯ�ء���˵����֮һ�������������ε�
�������Σ�Ϊ����������ɽ��ˮ���ԣ�ÿ�ξ���¥�ںȵ���������ͤ
�ڳ��赭�ţ�һ¥�������ϻ��������������ͼ��
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"yueyanglou1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 2,
	]));
	set("coor/x", -1450);
	set("coor/y", -2250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
