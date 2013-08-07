// Room: /d/fuzhou/matou.c
// Last Modified by winder on Sep. 20 2002

#include <ansi.h>
inherit RIVER;


void create()
{
	::create();
  set("short", "������ͷ");
  set("long", @LONG
�����Ǹ���������ͷ����ǰ����ˮ(river) ���η�������ֻ������
�����ϡ�������ͨ��������ƽ���Ŀʹ���
LONG );
  set("exits", ([
    "east" : __DIR__"zhongzhou",
  ]));
  set("no_clean_up", 0);
  set("outdoors", "fuzhou");
  set("coor/x", 1830);
  set("coor/y", -6340);
  set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("busy_msg",       "ֻ���ý�������������������������æ���š�����\n");
  set("come_msg_out",   "һ�ҿʹ�������ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("wait_msg",       "����һ�ҿʹ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű�����������ҡ���������ʹ�������ʻȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ���ҡ���������ʹ�������ʻȥ��\n");
  set("item_desc/river", HIC "\nֻ����������һ�ҿʹ���Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
  set("boat_short", "�ʹ�");    
  set("boat_desc",  @LONG
����һ���������Ϻ��еĴ�ʹ��������������ô�ٰѸ��ˡ�����
ʮ����ˮ�����ų����Ľ�����βһ����ʮ����������������֡������
ˮ�ǳ��峺�����ߵ�ɽ���վ����Դ��ɭ����ʱ������Ұ�޵�˻����
LONG );
  set("to",         "/d/yanping/longjindu");  // �����յ� /*   ��ѡ   */
  setup();
}
