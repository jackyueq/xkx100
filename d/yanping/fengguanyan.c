// Room: /d/yanping/fengguanyan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������ڽ�Ϫ֮�ϣ���������������ˮ����������֧��һ��
���֣�����������ճ���ĺ�ģ�ȫ�ǽ����ţ�̴��𳪣�˹�񾡻�
���ء�ƾ�����Ϫˮ���̣��ٷ����Ρ����ν��������������ɽˮ֮
����������ж�����Ȫ֮�¡���
    �԰�������վ���йٵ�ǰ�����ݡ�
LONG );
	set("exits", ([
		"up"        : __DIR__"mingcuige",
		"south"     : __DIR__"dongmen",
		"northwest" : __DIR__"yidao3",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1520);
	set("coor/y", -6160);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
