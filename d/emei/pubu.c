inherit ROOM;
int do_zuan();
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
����СϪ��ǰ�ߣ�����ˮ��Խ��Խ����ǰ������һ
�����ٲ���ˮ���ϰ��׸ߵ�������ֱк���£����������
ˮ�����ټ���ˮ����������ն��ǻ����ɵġ��ٲ�������
����һ��ɽ����
LONG
        );
        set("exits", ([
            "south" : __DIR__"yhchkou",
        ]));
        set("shorth", "�ٲ�");
	set("coor/x", -6200);
	set("coor/y", -1160);
	set("coor/z", 200);
	setup();
}
void init()
{
  add_action("do_zuan","zuan");
}
int do_zuan()
{
  object me = this_player();
  if((int)me->query_skill("dodge",1)<10)
    message_vision("$Nһ�������������һ��أ����ٲ����ȥ�����$N��ˮ�������˻�����\n",me);
  else
    {message_vision("$Nһ�������������һ��أ����ٲ����ȥ��$N�ɹ���������ٲ���\n",me);
     me->move(__DIR__"shdong1");
    }
  return 1;
}