// /d/yixing/cldamen.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>

void create()
{
  set("short", "����");
  set("long", @LONG
������������ϵĳ��ְ��ܶ����ڡ��ǳ��ְ��ڽ��������Ʒ�ͬ
С�ɣ������������ս����������Ⱥ�������϶��������Ļ�ͷ��������
������İ���վ�����ࡣ������һ������(bian)����յ�����������ҡ
�ڡ��Ա���һ����(bei) ���������һЩ���֡�
LONG );

  set("exits", ([
    "enter" : __DIR__"cldating",
    "south" : __DIR__"shulin4",
  ]));

  set("item_desc",([
    "bian" : 
"    ��������������������������������������\n"
"    ��������������������������������������\n"
"    �������������������֡��������������\n"
"    ��������������������������������������\n"
"    ��������������������������������������\n",
      "bei" :
"    ���֣��ݴ�����������ʫ����Ī�ǳ������ִ����������������ɡ���\n"
"    ���ְ�ԭ�ǽ����ϲ�������С��ӵ��ߴ�����ʱ����ʼ����ȵ��\n"
"    �����԰������ܹ����£���Ϊ�����ã�ʨ���ã������ã������úͱ�\n"
"    ���ã���ֶ���Ǳ鲼���أ��������ơ����ְ�����������а������\n"
"    ��ɢ���ڰ����������޲��������֡������о�С����ҥ�ƣ������޳���\n"
"    �޳����֡�\n",
  ]));

  set("objects",([
    __DIR__"npc/cl_qiu" : 1,
  ]));
  set("outdoors", "yixing");

  setup();
}

int valid_leave(object me, string dir)
{
  object ob;

  me = this_player();
  if( dir == "enter" &&
      objectp(ob = present("qiu shanfeng", environment(me))) &&
      living(ob) &&
       me->query("family/family_name") != HIC"���ְ�"NOR &&
      !me->query_temp("changle"))
    return notify_fail("��ɽ����������ǰ��˵�������������ô��һ�㽭����ض�����������Ҳ��Т��һ�����ӡ�\n");
  else
    {
//      me->delete_temp("changle");
      return ::valid_leave(me, dir);
   }
}