// /kaifeng/guandao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������ӿ��⸮�����ݸ��Ĺٵ�����������·�ΰ��Ϻ�����Ҳ��
�١�����ͨ�򿪷⣬����ͨ��������
LONG);
	set("exits", ([
  		"east"      : __DIR__"tokaifeng",
  		"northwest" : __DIR__"shulin",
	]));
        set("outdoors", "kaifeng");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
