// Room: /d/yanziwu/xunfeng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "Ѭ����");
	set("long", @LONG
һ��������С��������ˮ�ߣ�һ���������̫�������С��������
�������������Ƿ���һ���������Զ����ǧ���Σ�����Ů�ı��̳�ȹ��
�裬���н�����������ʧ�����£������ޱ߾��£�ȫ�����顣
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"   : __DIR__"path13",
	]));
	set("coor/x", 1270);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}