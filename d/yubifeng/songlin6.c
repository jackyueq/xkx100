// /yubifeng/songlin6.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @long
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�����һ��ɽ����¡�ɽ
�������ߣ�������һ���ʹܰ�������Ⱥɽ֮�У������쳣��Ī˵���ˣ���
��Գ��Ҳ�ǲ�����ȥ��	
long );
	set("exits", ([
		"east" : __DIR__"fengdi",
		"west" : __DIR__"songlin5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
