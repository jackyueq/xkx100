// Room: /d/yueyang/qiuyueqiao.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
λ��������������࣬Ϊ��԰ʯ���ţ�����ΪһƬ���������ŵİ�
԰����ӳ�ں�����ǡ��һ�����������¡���˵վ���������Ϲ����µ�ӳ
�����¾��У��ܿ����϶����������Ź㺮���ļ�į�龰��ֻ��ϧ���
�����Ѳ��������ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"xiaolu7",
		"northup"   : __DIR__"qiuyueting",
	]));
	set("coor/x", -1670);
	set("coor/y", 2330);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
