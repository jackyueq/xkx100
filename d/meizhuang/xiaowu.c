// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������Ժ󣬷������ﾹȻ��������Ĳ��ܴ�������
Ȼ����˵�ǽ�̻Իͣ��������������Ƶ����������������Σ������磬
��������......����ʤ����ǽ�Ϲ���һ����������һ�߰������١�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"xiaoyuan",
		"north" : __DIR__"neishi",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("heimuya")+"/gong" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 20);
	setup();
}
