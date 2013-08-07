#include <ansi.h>
inherit ITEM;
int query_autoload()
{
        return 1;
}

void create()
{
        set_name(HIW "��ҩ" NOR, ({ "bu yao", "yao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIY "����һ�������ڹ��Ĳ�ҩ��\n" NOR);
								set("unit", "��");
                set("value", 10000);
                set("weight", 300);
                //���ӵļ�����Ϊforce  
                //�����Ϊforce �Ǻ����force_point��ʾ���Ӿ���
                set("pill_skill", "force");
                // �Ƿ�Ϊ�����书
                set("skill_mapped", 1);

                //�����书���ټ��ܵ�
                set("pill_point", 100);

                //���Ӷ����������߾���
                set("force_point", 1);
								
								//���书�ɹ�������
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                //���书ʧ�ܵ�����  ���������pill_point����ʱ
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
                
                // �������������������������ǰ��������Ϣ����Ӧ��ȱʡ
                set("pill_msg3", HIM "��е��������ۺ���һЩ��\n" NOR);
                set("pill_msg4", HIR "��е���Ϣ���ȣ���������ҩ����\n" NOR);

        }
        setup();
}

init()
{
	add_action("do_eat","eat");
	}
int do_eat(string arg)
{
  string skill;
  int pot1, pot2, time;
	object me=this_player();
	int jingli_limit=me->query_skill("taoism", 1)*10;
	int neili_limit=me->query_skill("force")*10;
  pot1 = query("pill_point");
  pot2 = query("force_point");
  time = query("pill_point") / 40; 
  //����20000�������� ����500condition ==187 min ~= 3hour

//�Ǽ����͵�ҩ�����¼���Ч��ʱ��
  if (! query("pill_point"))
     time = 400 + query("force_point") * 10;
	if (!id(arg))
		return 0;
	if ((int)me->query_condition("pill_drug") > 0)
  {
    write("�����������Ϣδ���������������ܸе������嵴������óȻ��ʳ��\n");
    return 1;
  }
  if (me->is_busy())
  {
  	write("����æ���ء�\n");
  	return 1;
  	}
	me->apply_condition("pill_drug", time);
  message_vision(HIY + "$N"+ HIY+ "����һ" + query("unit")+query("name") + HIY +"����ʼ�˹�����ҩ����\n" NOR, me);
 log_file("gift/eat_skill",sprintf("%-20s eat %-10s [%s]\n",me->query("name")+"("+me->query("id")+")",this_object()->name(),ctime(time())));

        // �����ҩ�������Ӽ��ܵĹ��ܣ����֮
  if (query("pill_skill") && query("pill_point"))
    {
       // �ж����ӵļ����Ƿ�Ϊ���⼼��
         if (query("skill_mapped") >= 1)
            skill = me->query_skill_mapped(query("pill_skill"));
         else
            skill = query("pill_skill");
         tell_object(me, query("pill_msg1"));
         me->improve_skill(skill, pot1);
    }
// �����ҩ�������ӹ����Ĺ��ܣ����֮
  if (query("pill_skill") && query("force_point"))
    {
       // �ڹ���ҩ���������������������Ӿ���
       if (query("pill_skill") == "force")
           {
           // �ṩ����Ϣ
          		 if (me->query("max_neili") < neili_limit
          		  && query("pill_msg3"))
            tell_object(me, query("pill_msg3"));
          else if (me->query("max_neili") >= neili_limit
                && query("pill_msg4"))
            tell_object(me, query("pill_msg4"));
					//����
          me->add("max_neili",pot2 + random(pot2));
          if (me->query("neili") < me->query("max_neili"))
              me->set("neili",me->query("max_neili"));
                } else
                {
                        // �ṩ����Ϣ
                 if (me->query("max_jingli") < jingli_limit
                     			&& query("pill_msg3"))
                 	tell_object(me, query("pill_msg3"));
                 else if (me->query("max_jingli") >= jingli_limit
                           && query("pill_msg4"))
                   tell_object(me, query("pill_msg4"));
						//����
                 me->add("max_jingli",pot2 + random(pot2));
          if (me->query("jingli") < me->query("max_jingli"))
							me->set("jingli",me->query("max_jingli"));
                }
        }
        me->start_busy(random(3) + 3);

        destruct(this_object());

        return 1;
}
