// Room: /d/yanziwu/mingzhu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����������ɽׯ����¥�Ϸ���¥���÷ǳ������ûʣ��������ߣ���
�����ȣ�����һֻ�߸ߵ����Ĺ������¡�¥�������顱��ȡ��ʫ�䡰��
��������˫�����޲����δ��ʱ�������������˹�ȥ��һ������������
ʱ���Ѿ���ȥ�ܾ��ˣ���Ҷ���֪�����������֪������Ҳ����������
��ǰ�����ˡ�
LONG );
	set("exits", ([
		"south"  : __DIR__"path11",
	]));
	set("objects", ([
		__DIR__"npc/wangfuren" : 1,
	]));
	set("coor/x", 1240);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}