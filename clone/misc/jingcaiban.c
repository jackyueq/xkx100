// jingcaiban.c

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

// ȫ�ֱ��������������Ѻע����������
mapping *all_biao;
// ȫ�ֱ������˴�ΪĿǰ����
int num;
// ȫ�ֱ������˴�Ϊ���ս��
int jieguo;

// ��������Ϊ��������
int do_read(string);
int do_post(string);
int do_ya(string);
void enough_rest();

void create()
{
	set_name(HIY"���籭���ޣ���ʮǿ�����°�"NOR, ({ "board", "ban"}) );
	set("long", "����һ����¼��ҵľ���Ѻע����İ档
Ѻע��read rules���鿴Ŀǰ��Ͷע�����read ban��\n");
	set("unit", "��");
	set("no_put", 1);
	set("no_get", 1);
//���㲻�����Get
	set_weight(900000000);
	seteuid(getuid());
	restore();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_post", "post");
	add_action("do_ya","ya");
	add_action("do_duijiang","duijiang");
	add_action("do_duijiang","duixian");
}

string query_save_file()
{
// ����һ�������ļ���·��
	return DATA_DIR + "board/jingcai_b";
}

// �����ע
int do_ya(string arg)
{
	int i,j;
	object me,ob;
	mapping biao;
	
	me = this_player();
// ��ʾֹͣ��ע������ʦ��do_post()���������
	if(query("end_ya"))
		return notify_fail("��ֹʱ���ѹ����»ظ��硣\n");
// ��ֹ����ͬ��Ѻע��������
	if (query_temp("busy"))
		return notify_fail("�Ժ�........\n");
// ��������ϵĲ���
	if(me->query("jingcai"))
		return notify_fail("ÿ��ֻ��Ѻһ�Σ�\n");
// �������ָ��
	if(!arg || sscanf(arg, "%d %d", i, j) != 2)
		return notify_fail("�����ʽ��ya <����> <�������ƽ�>\n");
// �ų�һЩ�����ܵ�Ѻע����
	if(i<10 || i>22)
		return notify_fail("�����ܰɣ����ǲ��������Ǯ��\n");
// ����1gold
	if(j < 1)
		return notify_fail("�����׬����\n");
// ���ޣ��������ɵ���
	if(j > 1000)
	    return notify_fail("Ѻ��̫�࣬������1000��\n");
	if((int)j>me->query("balance")/10000)
// Ǯׯ�Ĵ���Ѻ��Ǯ
		return notify_fail("���ﲻ���ֽ𣡵�Ǯׯ�湻��Ǯ��������\n");
	message_vision("$N���˰������������������Ϊ�й������õ� "+i+" �֣�Ѻ "+j+" ���ƽ𣡡�\n",me);
	me->add("balance",-j*10000);
	tell_object(me,"Ǯׯ�Ѿ��۳�����Ѻ�µ�"+j+"���ƽ���Ⱥ����ɣ�\n");
// �������������Ѻ�Ľ��
	me->set("jingcai/win",i);
// Ѻ�Ļƽ���
	me->set("jingcai/gold",j);
// ����һ����¼�����Ѻע���ݵ�ӳ��
	biao = ([
		"id":me->query("id"),
		"name":me->query("name"),
		"win":i,
		"gold":j,
	]);
	if( !pointerp(all_biao) ) all_biao = ({ biao });
	else all_biao += ({ biao });
//���������ļ���Ӧ��.o�ļ���
	save();
	remove_call_out("enough_rest");
//1���ȡ��busy
	call_out("enough_rest", 1);
	return 1;
}

// ��ʦר�ã��������
int do_post(string arg)
{
	int i;
	object me= this_player();

	if(!wizardp(me)) return 0;
	if( !arg) return notify_fail("��Ҫ����ʲô��\n");
// ֻ�����ֱ�ʾ���¼�ʱ���
	if(sscanf(arg, "%d", i)==1 )
	{
// num��ȫ�̱���
		if( i > num )
		{
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ���˵���°��й��ӵ�ǰ�÷��� "+num+" ����Ϊ "+i+" �֣�\n"NOR, users());
// ����
			num = i;
			save();
			return 1;
		}
		else return notify_fail("�й��ӵ÷ֻ�Խ��Խ����\n");
	}
// ��-last��������ʾ�������ս��
	if(sscanf(arg, "-last %d", i)==1 )
	{
		if( i >= num )
		{
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ���˵���°����ս���������� "+jieguo+" �֣�Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR, users());
// ����
			jieguo = i;
			save();
			return 1;
		}
		else return notify_fail("�й��ӵ÷ֻ�Խ��Խ����\n");
	}
	if(arg=="end")
	{
// ֹͣѺע
		set("end_ya",1);
		message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°濪ʼֹͣ��ע�����ע���������\n"NOR, users());
		save();
		return 1;
	}
	return notify_fail("��Ҫ���й��ӵ÷��Ƕ��٣�\n");
}
// ��Ҳ鿴
int do_read(string arg)
{
	int i,j,k;
	object me;
	string name,str,str1,str2;
	mapping biao;
	
	me = this_player();
	if(arg == "rules")
	{
//����������ÿ����ʦ��ƵĶ�
		write("
    ���籭��Χ������ʮǿ�����飬�й������ü��֣���ӭ�ڴ�Ѻע��
Ѻע���Իƽ�Ϊ��λ����߿�Ѻһǧ�ƽ�����ҲҪѺһ���ƽ��ֽ�
���գ������ȴ��Ǯׯ��Ѻ�ĺ�Ǯׯֱ�ӿ�Ǯ��Ѻ��ʱ�䵽ʮ��ʮ����
��ֹ��ѺС��ʮ���ֵ�����һ��ʮ����Ѻʮ������ʮ֮���������һ��
������ʮ���ϵ�������һ��ʮ�壬����������Ѻ���߰����������ƽ�
��������ա�����˺�� "HIY"ya <����> <�������ƽ�> "NOR"��
    ��Ȼÿ��IDֻ��Ѻһ�Σ�Ѻ�������ڣ�\n\n");
		write("��������ʹ��duixianָ���Ľ����Զ��������ʻ���\n");
		return 1;
	}
	if(arg == "ban")
	{
//���˷����Ĳ���
		if(num) write( "������������������������������������\n"HIG"����ʮǿ�����й��ѻ� "HIY+num+HIG" �֣�");
		write(!jieguo ? RED"����Ͷע�У�" : HIR"��ʼ�ҽ�(duijiang)�ˣ�");
//��ʾ��û������
		if( !pointerp(all_biao) || !sizeof(all_biao) )
		{
			write(NOR"\n��û���˿�ʼͶע��\n");
			return 1;
		}
		write(NOR"\n���� "+sizeof(all_biao)+" �����Ͷע��\n"
		HIY"�������������Ԥ�����  ��Ѻ�ƽ���"HIG"��"HIY"�������������Ԥ���������Ѻ�ƽ���\n"
		HIG"�����������������������������������ࡪ��������������������������������\n");
		str1 = HIM"�Ѿ��ҹ�������ң�                "HIG"��\n"NOR;
		str2 = HIM"��δ�ҹ�������ң�                "HIG"��\n"HIC;
		j = 0;
		k = 0;
// all_biaoҲ��ȫ�ֱ��������ļ�ͷ
		for(i=0; i<sizeof(all_biao); i++)
		{
// ȡ��ÿ��Ѻע��ҵ�����
			name = all_biao[i]["name"]+"("+all_biao[i]["id"]+")";
// dui����������ڶҽ������ģ����ʾû�ҽ��ģ�����str2
			if(!(int)all_biao[i]["dui"])
			{
				str2 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],(int)all_biao[i]["gold"],j%2?"\n":HIG"��"HIC,);
// j�������k����Ϊ������һ�У������õ�j%2���ǳ�2ʣ�µ�������Ϊ0�ͻ���
				j++;
			}
// ��dui�����ģ�����str1
			else
			{
				str1 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],(int)all_biao[i]["gold"],k%2?"\n":HIG"��"HIC,);
				k++;
			}
		}
/* �����str1��str2���Ը��ݲ�ͬ��������ֲ�ͬ����Ϣ�������ڱ����У���
�Ը���all_biao[i]["win"]�Ƿ����num����Ŀǰ�ķ��������ж���Щ��һ���
ϣ������Щ����Ѿ�����̭��str1="�޻�ϣ�������"��......  */
//��ʾ��Ϣ
		write(str1+"\n"+str2+"\n"NOR);
		return 1;
	}
	else
		write("��Ҫ��ʲô��Ѻע������read rules��Ѻע�����read ban��\n");
	return 1;
}

void enough_rest()
{
	delete_temp("busy");
}
// �ҽ�ָ��
int do_duijiang()
{
	int i,j;
	object ob, me = this_player();
	mapping biao, jingcai;

// û��jieguo�ͱ�ʾû�п�ʼ�ҽ�
	if(!jieguo) return notify_fail("��δ���ҽ�ʱ�䣡\n");
// �������ϲ���
	if(!jingcai = me->query("jingcai"))
		return notify_fail("��û�н��ģ������Ѿ��ҹ����ˣ�\n");
	if(query_temp("busy")) return notify_fail("�Ժ�........\n");
	set_temp("busy",1);
// ������������н�
	if(jingcai["win"]==jieguo)
	{
// 1��15
		if(jingcai["win"]>22) i = jingcai["gold"]*15;
// 1��6
		else if(jingcai["win"]>14) i = jingcai["gold"]*6;
// 1��12
		else i = jingcai["gold"]*12;
// ��Щ�����԰����趨�Ĺ�������
		write("��Ѻ "+jingcai["win"]+" �� "+jingcai["gold"]+" ���ƽ𣬰��涨�ý��� "+i+" ���ƽ��ѻ������Ǯׯ�ʻ���\n");
		message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ�"+me->name()+"�ҽ��õ� "+chinese_number(i)+" ���ƽ�\n"NOR, users());
		me->add("balance",i*10000);
	}
// û�жԵ�Ҳ�������Ž���
	else
	{
		ob = new("/clone/food/jitui");
		ob->move(me);
		write("��ûѺ�ԣ�����һ����ο��������һ�����Ȱɣ�\n");
		message_vision( HIY"���±���ͷͻȻ���һ�������ˡ��ص���һ���͹��ļ��ȣ����õ���$N�����С�\n"NOR,me);
	}
	for(j=0; j<sizeof(all_biao); j++)
	{
// ��ʾ���˶ҹ�����
		if(all_biao[j]["id"]==me->query("id"))
			all_biao[j]["dui"] = 1;
	}
// ����
	save();
// ���ϲ���ȡ�����Է��ظ��ҽ�
	me->delete("jingcai");
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}
