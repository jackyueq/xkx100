// Room: /d/heimuya/dating2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "�׻���");
	set("long", @LONG
���ǡ�������̡��µڶ����ã��׻��õĴ�������Ŀ��ȥ��һ�ض�
����Ѫ����Ȼ����ǰ������һ����ս����������һ���ľ��(bian)����
�ϱ������м���Ѫ��(zi)��
LONG    );
	set("exits", ([
		"west" : __DIR__"baistep1",
		"east" : __DIR__"linjxd6",
	]));
	set("item_desc", ([
		"bian": "����д�����������գ��׻����죻ǧ�����أ�һͳ���� ��\n",
		"zi" : "����д������ɽ���ӣ���ɱа�̡�\n" 
	]) );
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}