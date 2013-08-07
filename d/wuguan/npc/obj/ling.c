// d/wuguan/obj/ling.c �������ҳ�

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("�Ƽ���", ({"tuijian ling", "ling"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���Ǵӳ��е�����õ��Ƽ��������������Ժ�����ڵı��ŵ���\n"+
		"һ��̽��(tantao)�书�ˡ�\n");
		set("unit", "��");
		set("no_get",1);
		set("no_get_from",1);
		set("no_put",1);
		set("no_give",1);
	}
}
init()
{
	add_action("do_tantao","tantao");
}
int do_tantao(string arg)
{
 	object me=this_player();
	object env=environment(me);
	object ob;
	string type,with;
  string my_fam = me->query("family/family_name");
	if (strsrch(file_name(env),"d/wuguan/") < 0)
		return notify_fail("������ݣ�˭����ʶ����Ƽ��\n");
	if (!arg ||sscanf(arg,"%s with %s",type,with)!=2)
		return notify_fail("��ʽ��tantao <����> with <ĳ��>\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���������ɡ�\n");
	if (type!="force" && type!="dodge" && type!="parry")
		return notify_fail("��ֻ�ܺͱ������ۻ����ڹ��������Ṧ�ͻ����мܵ����ݡ�\n");
	if( !objectp(ob = present(with, environment(me))))
		return notify_fail("�����˭һ�����ۣ�\n");
	if (!me->query("family"))
	 return notify_fail("�㻹���ȼ���һ�������ٺͱ�����������ɡ�\n");
	 if (me->query("jing")<20)
	 return notify_fail("������̫���ˣ���Ϣһ�������ɡ�\n");
 	if ((me->query("potential") - me->query("learned_points"))< 2)
		return notify_fail("���Ǳ�ܲ������˼�һ�����������ˡ�\n");
	if((my_fam=="��ң��" && ob->query("id")=="xiaoyao dizi")
	||(my_fam=="����" && ob->query("id")=="mingjiao bangzhong")
	||(my_fam=="�һ���" && ob->query("id")=="taohuadao dizi")
	||(my_fam=="������" && ob->query("id")=="xiao heshang")
	||(my_fam=="������" && ob->query("id")=="shenlong dizi")
	||(my_fam=="������" && ob->query("id")=="tiandihui bangzhong")
	||(my_fam=="̩ɽ��" && ob->query("id")=="taishan dizi")
	||(my_fam=="������" && ob->query("id")=="lingxiao dizi")
	||(my_fam=="����Ľ��" && ob->query("id")=="murong dizi")
	||(my_fam=="������" && ob->query("id")=="xingxiu dizi")
	||(my_fam=="��Ĺ��" && ob->query("id")=="gumu dizi")
	||(my_fam=="���ư�" && ob->query("id")=="tiezhang dizi")
	||(my_fam=="������" && ob->query("id")=="xiao shitai")
	||(my_fam=="ȫ���" && ob->query("id")=="daotong")
	||(my_fam=="�嶾��" && ob->query("id")=="wudu dizi")
	||(my_fam=="��ɽ��" && ob->query("id")=="hengshan nvni")
	||(my_fam=="��ɽ��" && ob->query("id")=="hengshan dizi")
	||(my_fam=="�����" && ob->query("id")=="qingcheng dizi")
	||(my_fam=="�컨��" && ob->query("id")=="honghuahui bangzhong")
	||(my_fam=="ѩɽ��" && ob->query("id")=="xueshan dizi")
	||(my_fam=="����ɽ��" && ob->query("id")=="baituo dizi")
	||(my_fam=="��ľ��" && ob->query("id")=="riyuejiao dizi")
	||(my_fam=="������" && ob->query("id")=="kunlun dizi")
	||(my_fam=="��������" && ob->query("id")=="nanshaolin dizi")
	||(my_fam=="��ɽ��" && ob->query("id")=="huashan dizi")
	||(my_fam=="��ɽ��" && ob->query("id")=="songshan dizi")
	||(my_fam=="�䵱��" && ob->query("id")=="daotong")
	||(my_fam=="����μ�" && ob->query("id")=="tianlongsi dizi")
	|| (my_fam=="ؤ��" && ob->query("id")=="xiao jiaohua"))
		{
		if (me->query("teachwg/"+type)>=100)
		return notify_fail("�����书���Ѿ��ʵò���ˣ���������ɡ�\n");
		else if(me->query_skill(type,1) < me->query("teachwg/"+type) )
			return notify_fail("�����书���Լ�ûѧ�����ٰ�����ô�ͱ���һ�����ۡ�\n");
		else 
			{
				tell_object(me,"�㿪ʼ��"+ob->query("name")+"һ�����۹���"+to_chinese(type)+"�����⡣\n");
				if (random(5)<2)
					tell_object(me,"���"+ob->query("name")+"������һ���,˭Ҳû����˭����˼��\n");
				else
					{
					tell_object(me,"���"+ob->query("name")+"������һ�������"+to_chinese(type)+"����������һЩ��\n");
					me->add("family/fealty",3);
					write(HIW"����Լ��Ժ���"+me->query("family/family_name")+"�ķ�չǰ�����������ˡ�\n"NOR);
					me->add("teachwg/"+type,1);
					me->add("learned_points",2);
					me->improve_skill(type, 2*me->query("teachwg/"+type));
			    }
			}
				me->add("jing",-(10+random(5)));
				return 1;
			}
			else
	 			return notify_fail("������"+ob->query("name")+"û�к���һ�������������˼��\n");	
}