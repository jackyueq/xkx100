//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "������ͷ");
	set("long", @LONG
��ǰ��һ�����η����Ĵ� (river)������������ǧ������������
�ɴ��������������ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG );
	set("exits", ([
		"west" : __DIR__"hzjie2",
	]));
	set("item_desc", ([
		"river" : "�������м�ֻ�ɴ���Ҳ��(yell)һ�����Ҿ���������\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1490);
	set("coor/y", -2110);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һֻľ��������ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ý�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬ľ������ʻȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬ľ������ʻȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ���������м�ֻ�ɴ���Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
    һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ��������׳�������ֳֳ�
��ݣ����ڴ�β�����س��Ŵ���һ�߻�ߺ���Ŵ��裺���ķ���·������
ˮ��������
LONG );
  set("to",         __DIR__"matou2");  // �����յ� /*   ��ѡ   */
	setup();
}
